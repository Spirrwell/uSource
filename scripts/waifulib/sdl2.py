# encoding: utf-8
# sdl2.py -- sdl2 waf plugin
# Copyright (C) 2018 a1batross
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

import os

def configure(conf):
    conf.env.INCLUDES_SDL2 = [os.path.abspath(conf.env.VCPKG_DIR + '/include/'), os.path.abspath(conf.env.VCPKG_DIR + '/include/SDL2/')]
    conf.env.LIB_SDL2 = ['SDL2']
    conf.env.LIBPATH_SDL2 = [os.path.abspath(conf.env.VCPKG_DIR + '/lib/')]
    conf.env.HAVE_SDL2 = 1
