#!/usr/bin/env python3
# encoding: utf-8
from waflib.Task import Task
from waflib.TaskGen import extension
import os 

class protoc(Task):
    run_str = '${PROTOC} ${SRC} --cpp_out=. -I..'
    color='BLUE'
    ext_out=['.h', '.pb.cc']

@extension('.proto')
def compile_protoc(self, node):
    cpp_node = node.change_ext('.pb.cc')
    hpp_node = node.change_ext('.pb.h')
    self.create_task('protoc', node, [cpp_node, hpp_node])
    self.source.append(cpp_node)
    self.env.append_value('INCLUDES', ['.', self.env.ROOT + '/build'] )

    self.use = self.to_list(getattr(self, 'use', '')) + ['PROTOBUF']

def configure(conf):
    conf.env.INCLUDES_PROTOBUF = [conf.env.VCPKG_DIR + '/include/', conf.env.VCPKG_DIR + '/include/protobuf/' ]
    conf.env.LIB_PROTOBUF = ['protobuf']
    conf.env.LIBPATH_PROTOBUF = [conf.env.VCPKG_DIR + '/lib/']
    conf.env.HAVE_PROTOBUF = 1
    conf.check_cfg(package="protobuf", uselib_store="PROTOBUF")
    conf.find_program(os.path.abspath('{0}/tools/protobuf/protoc'.format(conf.env.VCPKG_DIR)), var='PROTOC')
