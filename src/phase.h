//
//  Copyright (C) 2011-2013  Nick Gasson
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef _PHASE_H
#define _PHASE_H

#include "tree.h"

// Annotate types and perform other semantics checks on a tree.
// Returns false on error.
bool sem_check(tree_t t);

// The number of errors found during the semantic check phase.
int sem_errors(void);

// Replace all alias references with the underlying object.
void unalias(tree_t top);

// Fold all constant expressions
void simplify(tree_t top);

// Number of errors found during simplification
int simplify_errors(void);

// Evaluate a function call at compile time
tree_t eval(tree_t fcall);

// Elaborate a top level entity
tree_t elab(tree_t top);

// Generate LLVM bitcode for an elaborated design
void cgen(tree_t top);

// Dump out a VHDL representation of the given unit
void dump(tree_t top);

// Print out the interconnect nets in an elaborated design
void dump_nets(tree_t top);

// Optimise elaborated design
void opt(tree_t top);

// Link together bitcode packages with elaborated design
void link_bc(tree_t top);

// True if the package contains shared variables or signals which
// must be run through code generation
bool pack_needs_cgen(tree_t t);

// Groups nets which never have sub-elements assigned.
void group_nets(tree_t top);

#endif  // _PHASE_H
