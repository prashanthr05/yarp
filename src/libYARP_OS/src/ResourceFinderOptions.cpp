/*
 * Copyright (C) 2013 Istituto Italiano di Tecnologia (IIT)
 * Authors: Paul Fitzpatrick, Daniele E. Domenichelli
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <yarp/os/ResourceFinderOptions.h>

using namespace yarp::os;

ResourceFinderOptions::ResourceFinderOptions(SearchLocations searchLocations,
                                             DuplicateFilesPolicy duplicateFilesPolicy,
                                             SearchFlavor searchFlavor,
                                             const ConstString& resourceType,
                                             MessageFilter messageFilter) {
    this->searchLocations = searchLocations;
    this->duplicateFilesPolicy = duplicateFilesPolicy;
    this->searchFlavor = searchFlavor;
    this->resourceType = resourceType;
    this->messageFilter = messageFilter;
}
