/**
 * @file XRayVisitor.cpp
 *
 * @author Peyton Nagher
 */

#include "pch.h"
#include "XRayVisitor.h"

/**
 * Sets a member variable from the X-Ray item
 *
 * @param xRay
 */
void XRayVisitor::VisitXRay(ItemXRay* xRay)
{
    mXRay = xRay;
}