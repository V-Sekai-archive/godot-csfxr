project('csfxr', 'c', default_options : ['default_library=static', 'c_std=gnu89'])
incdir = include_directories('include')


cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : true)
#m_dep = dependency('m')
libcsfxr = library('csfxr', 'src/csfxr.c', include_directories : incdir, dependencies:m_dep)
csfxr_dep = declare_dependency(link_with : libcsfxr, include_directories : incdir)


if not meson.is_subproject()

#Basic test binary
depao = dependency('ao')

executable('basic', 'src/examples/basic.c', include_directories : incdir, dependencies: [csfxr_dep, depao])

#Complex test binary
#executable('test', 'src/examples/test.c', include_directories : incdir, dependencies: csfxr_dep)

endif

