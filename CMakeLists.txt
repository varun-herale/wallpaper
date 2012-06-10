PROJECT(wallpaper)

FIND_PACKAGE(KDE4 REQUIRED)

INCLUDE(KDE4Defaults)
 
include_directories( ${KDE4_INCLUDES} )
 
set( KDE4ProjectSources main.cpp window.cpp )
 
kde4_add_executable( wallpaper ${KDE4ProjectSources} )
 
target_link_libraries( wallpaper ${KDE4_KDEUI_LIBS} ${KDE4_KPARTS_LIBS} )
 
install( TARGETS wallpaper  ${INSTALL_TARGETS_DEFAULT_ARGS} )