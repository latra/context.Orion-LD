#ifndef SRC_LIB_ORIONLD_TYPES_ORIONLDPROBLEMDETAILS_H_
#define SRC_LIB_ORIONLD_TYPES_ORIONLDPROBLEMDETAILS_H_

/*
*
* Copyright 2019 FIWARE Foundation e.V.
*
* This file is part of Orion-LD Context Broker.
*
* Orion-LD Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion-LD Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion-LD Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* orionld at fiware dot org
*
* Author: Ken Zangelin
*/
extern "C"
{
#include "kjson/KjNode.h"                                         // KjNode
}

#include "orionld/types/OrionldResponseErrorType.h"               // OrionldResponseErrorType



// -----------------------------------------------------------------------------
//
// OrionldProblemDetails -
//
typedef struct OrionldProblemDetails
{
  OrionldResponseErrorType  type;
  char*                     title;
  char*                     detail;
  int                       status;
  char                      titleAndDetailBuffer[256];
  char*                     titleAndDetail;
  char*                     field;
  char*                     attribute;
} OrionldProblemDetails;



// -----------------------------------------------------------------------------
//
// orionldProblemDetailsFill -
//
void orionldProblemDetailsFill
(
  OrionldProblemDetails*   pdP,
  OrionldResponseErrorType type,
  const char*              title,
  const char*              detail,
  int                      status
);



// -----------------------------------------------------------------------------
//
// pdField - add value for OrionldProblemDetails::field
//
extern void pdField(const char* fieldName);



// -----------------------------------------------------------------------------
//
// pdAttribute - add value for OrionldProblemDetails::attribute
//
extern void pdAttribute(const char* attrName);



// ----------------------------------------------------------------------------
//
// pdTreeCreate -
//
extern KjNode* pdTreeCreate
(
  OrionldResponseErrorType  errorType,
  const char*               title,
  const char*               detail
);

#endif  // SRC_LIB_ORIONLD_TYPES_ORIONLDPROBLEMDETAILS_H_
