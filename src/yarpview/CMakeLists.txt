# Copyright (C) 2014 Istituto Italiano di Tecnologia (IIT)
# Author: Daniele E. Domenichelli <daniele.domenichelli@iit.it>
# CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT

if(CREATE_YARPVIEW)

  include(YarpUseQt5)

  set(QtYARPViewPlugin_QMLDIR "robotology/yarp/view")

  add_subdirectory(plugin)
  add_subdirectory(src)

endif()
