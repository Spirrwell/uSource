import os

def configure(conf):
    conf.env.INCLUDES_TBB = [os.path.abspath(conf.env.VCPKG_DIR + '/include/'), os.path.abspath(conf.env.VCPKG_DIR + '/include/tbb/')]
    conf.env.LIB_TBB = ['tbb']
    conf.env.LIBPATH_TBB = [os.path.abspath(conf.env.VCPKG_DIR + '/lib/')]
    conf.env.HAVE_TBB = 1
