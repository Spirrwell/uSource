import os

def configure(conf):
    conf.env.INCLUDES_FREETYPE = [os.path.abspath(conf.env.VCPKG_DIR + '/include/'), os.path.abspath(conf.env.VCPKG_DIR + '/include/freetype/')]
    conf.env.LIB_FREETYPE = ['freetype']
    conf.env.LIBPATH_FREETYPE = [os.path.abspath(conf.env.VCPKG_DIR + '/lib/')]
    conf.env.HAVE_FREETYPE = 1
