==Design Choices==

The problem is a classic graph visiting algorithm with custom visiting rules.
I wanted to develop a generic framework for the problem with good decoupled implementations and modular components.
I did start a Boost graph implementation but I didn't like the clutter which is unavoidable unfortunately in this cases, but I left a bit of implementation in the file names called MapIsland.cpp.boost just to give an idea.

==Compilation==
The source code was developed with CodeBlocks on an Ubuntu machine with Boost libraries flags enabled.

==TO DO==
I didn't have time to implement the rules for visiting the graph unfortunately but the rest of is functional.

