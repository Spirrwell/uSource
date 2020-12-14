import os

def configure(conf):
    conf.env.INCLUDES_GLEW = [os.path.abspath(conf.env.VCPKG_DIR + '/include/')]
    conf.env.LIB_GLEW = ['GLEW']
    conf.env.LIBPATH_GLEW = [os.path.abspath(conf.env.VCPKG_DIR + '/lib/')]
    conf.env.HAVE_GLEW = 1
