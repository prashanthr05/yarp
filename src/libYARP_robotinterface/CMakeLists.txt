# Copyright (C) 2006-2019 Istituto Italiano di Tecnologia (IIT)
# Copyright (C) 2006-2010 RobotCub Consortium
# All rights reserved.
#
# This software may be modified and distributed under the terms of the
# BSD-3-Clause license. See the accompanying LICENSE file for details.

if (YARP_COMPILE_libYARP_robotinterface)

  project(YARP_robotinterface)

  set(YARP_robotinterface_HDRS include/yarp/robotinterface/Action.h
                     include/yarp/robotinterface/Device.h
                     include/yarp/robotinterface/CalibratorThread.h
                     include/yarp/robotinterface/Param.h
                     include/yarp/robotinterface/Robot.h
                     include/yarp/robotinterface/RobotInterfaceDTD.h
                     include/yarp/robotinterface/Types.h
                     include/yarp/robotinterface/XMLReader.h)

  set(YARP_robotinterface_IMPL_HDRS)

  set(YARP_robotinterface_SRCS src/Action.cpp
                     src/Device.cpp
                     src/CalibratorThread.cpp
                     src/Param.cpp
                     src/Robot.cpp
                     src/RobotInterfaceDTD.cpp
                     src/Types.cpp
                     src/XMLReader.cpp)

  source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
               PREFIX "Source Files"
               FILES ${YARP_robotinterface_SRCS})
  source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}"
               PREFIX "Header Files"
               FILES ${YARP_robotinterface_HDRS}
                     ${YARP_robotinterface_IMPL_HDRS})

  add_library(YARP_robotinterface ${YARP_robotinterface_SRCS}
                        ${YARP_robotinterface_HDRS}
                        ${YARP_robotinterface_IMPL_HDRS})
  add_library(YARP::YARP_robotinterface ALIAS YARP_robotinterface)

  target_include_directories(YARP_robotinterface PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                                              $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

  target_link_libraries(YARP_robotinterface PUBLIC YARP::YARP_conf
                                         YARP::YARP_OS
                                         YARP::YARP_sig
                                  PRIVATE YARP::YARP_eigen)
  list(APPEND YARP_robotinterface_PUBLIC_DEPS YARP_conf
                                    YARP_OS
                                    YARP_sig)
  list(APPEND YARP_robotinterface_PRIVATE_DEPS YARP_eigen)

  target_link_libraries(YARP_robotinterface PRIVATE Eigen3::Eigen)
  list(APPEND YARP_robotinterface_PRIVATE_DEPS Eigen3)

  target_compile_features(YARP_robotinterface PUBLIC cxx_override)

  set_property(TARGET YARP_robotinterface PROPERTY PUBLIC_HEADER ${YARP_robotinterface_HDRS})
  set_property(TARGET YARP_robotinterface PROPERTY PRIVATE_HEADER ${YARP_robotinterface_IMPL_HDRS})
  set_property(TARGET YARP_robotinterface PROPERTY VERSION ${YARP_VERSION_SHORT})
  set_property(TARGET YARP_robotinterface PROPERTY SOVERSION ${YARP_SOVERSION})

  install(TARGETS YARP_robotinterface
          EXPORT YARP_robotinterface
          COMPONENT YARP_robotinterface
          RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
          LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
          ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
          PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/yarp/robotinterface"
          PRIVATE_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/yarp/robotinterface/impl")

  include(YarpInstallBasicPackageFiles)
  yarp_install_basic_package_files(YARP_robotinterface
                                   DEPENDENCIES ${YARP_robotinterface_PUBLIC_DEPS}
                                   PRIVATE_DEPENDENCIES ${YARP_robotinterface_PRIVATE_DEPS})

  set_property(TARGET YARP_robotinterface PROPERTY FOLDER "Libraries")
endif()
