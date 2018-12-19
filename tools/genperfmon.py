#!/usr/bin/env python
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# ABOUT
#   This script is used to generate the trace implementations of all
#   OpenGL calls. When executed, it reads the specs for the OpenGL calls
#   from the files GLES2/gl2_api.in, GLES2/gl2ext_api.in, GLES_CM/gl_api.in,
#   and GLES_CM/glext_api.in, and generates trace versions for all the
#   defined functions.
#
# PREREQUISITES
#   To generate C++ files, this script uses the 'pyratemp' template
#   module. The only reason to use pyratemp is that it is extremly
#   simple to install:
#   $ wget https://www.simple-is-better.org/template/pyratemp-latest/pyratemp.py
#   Put the file in the GLES_trace/tools folder, or update PYTHONPATH
#   to point to wherever it was downloaded.
#
# USAGE
#   $ cd GLES_trace       - run the program from GLES2_trace folder
#   $ ./tools/genapi.py   - generates a .cpp and .h file
#   $ mv *.cpp *.h src/   - move the generated files into the src folder
import sys

sys.dont_write_bytecode = True

from lxml import etree
import os


class PerfMon:
    def __init__(self):
        return None
    def loadElementTree(self, tree):
        return 0

    def genModule_OLD(self, gen):
        print "\nvoid perf_event_module()\n{"
        qs = gen.findall("entity")
        for q in qs:
            print "\t%s %s;" % (q.attrib["datatype"], q.attrib["name"])
        print "}"

        return 0

    def genModule(self, gen):
        ro = "%s" % gen.getroot().get("name")
        nm = "__%s" % ro

        print "\nvoid %s_module()\n{" % (ro)
        a = gen.findall("group")
        for i in a:
            qs = i.findall("member")
            for q in qs:
                print "\t__gluey::group_set_tag(GROUP_%s, MEMBER_%s);" % (i.attrib["name"].upper(), q.text.upper())

        print ""

        a = gen.findall("member")
        for i in a:
            print "\t__gluey::member_set(MEMBER_%s, member_%s);" % (i.attrib["name"].upper(), i.attrib["name"])
        print "}"
        return 0

    def genTags(self, gen):
        tags = set()
        b = gen.findall("group/member")
        for x in b:
            tags.add(x.text)
        print "enum tag_type {"
        for tag in tags:
            print "\tGROUP_%s," % tag.upper()
        print "\tMAX_GROUP_TYPE"
        print "};"
    def genTagsBipos(self, gen):
        tags = set()
        b = gen.findall("group/member")
        for x in b:
            tags.add(x.text)

        print "\nenum tag_type_bitpos {"
        for tag in tags:
            print "\tBITPOS_GROUP_%s = 1 << GROUP_%s," % (tag.upper(), tag.upper())
        print "\tMAX_BITPOS_GROUP_TYPE"
        print "};"

    def genTagNames(self, gen):
        tags = set()
        b = gen.findall("group/member")
        for x in b:
            tags.add(x.text)
        print "\nconst char* tag_names[] {"
        for tag in tags:
            print "\t\"%s\"," % tag
        print "\tnullptr"
        print "};"


    def genDescription(self, gen):
        a = gen.findall("member")

        for i in a:
            print "\nstruct __gluey::description %s_counter_description[] =\n{" % (i.attrib["name"])
            qs = i.findall("entity")
            for q in qs:
                cfg = q.find("extra").get("config")
                bitop = cfg.replace("BITOR","|").replace("SHL","<<")
                print "\t{ %s, \"%s\", \"%s\"}," % (bitop, q.attrib["brief"], q.attrib["description"])
            print "};"
        return 0
#void perf_event_module()

    def genBitpos(self, gen):
        a = gen.findall("member")

        print "\nenum counter_bitpos {"
        for i in a:
            print "\tBITPOS_%s," % (i.attrib["name"].upper())
        print "\tMAX_COUNTER_BITPOS"
        print "};"
        return 0

    def genMetricInit(self, gen):
        a = gen.findall("member")

        print "\nvoid metrics_init() {"
        for i in a:
            tags = i.findall("tag")
            for t in tags:
                print "\tcounter_collection[GROUP_%s].members" % (t.attrib["name"].upper())
                print "\t\t.set(BITPOS_%s);\n" % (i.attrib["name"].upper())
        print "}"
        return 0

    def genMember(self, gen):
        a = gen.findall("member")

        for i in a:
            qs = i.findall("entity")
            print "\nstruct __gluey::member_priv_t member_%s = { %d, %s, &backend_perf_event, %s_counter_description};" % (i.attrib["name"],len(qs), i.attrib["type"], i.attrib["name"])
        return 0

    def genCollection(self, gen):
        print "struct collection {"
        print "\tstd::bitset<MAX_COUNTER_BITPOS> members;"
        print "} counter_collection[MAX_GROUP_TYPE];"

if __name__ == '__main__':
    # Load & parse perfmon
    gh = PerfMon()

    tree = etree.parse("perf_event_open.xml")

    xmlschema_tree = etree.parse("metrics.xsd")
    xmlschema = etree.XMLSchema(xmlschema_tree)
    xmlschema.assertValid(tree)

    gh.loadElementTree(tree)

    #gh.genTags(tree)
    #gh.genTagsBipos(tree)
    #gh.genTagNames(tree)
    #gh.genBitpos(tree)
    gh.genDescription(tree)
    gh.genMember(tree)
    gh.genModule(tree)
