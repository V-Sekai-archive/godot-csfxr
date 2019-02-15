project('bepx', 'c', default_options : ['default_library=static', 'c_std=gnu89'])
incdir = include_directories('include')

libbepx = library('bepx', 'src/sfxr.c', 'src/bepx.c', include_directories : incdir)
bepx_dep = declare_dependency(link_with : libbepx, include_directories : incdir)

if not meson.is_subproject()

#Basic test binary
executable('bepxbasic', 'src/examples/basic.c', include_directories : incdir, dependencies: bepx_dep)

#Complex test binary
executable('bepxtest', 'src/examples/test.c', include_directories : incdir, dependencies: [bepx_dep])

endif

