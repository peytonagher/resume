/**
 * @file DigitResetVisitor.cpp
 *
 * @author Peyton Nagher
 */

#include "pch.h"
#include "DigitResetVisitor.h"

/**
 * Visit a moveable digit object
 * @param digit Object to be visited
 */
void DigitResetVisitor::VisitDigitMovable(ItemDigitMovable *digit)
{
    digit->SetMoved(false);
}