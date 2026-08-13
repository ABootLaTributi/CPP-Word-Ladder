# CPP-Word-Ladder
C++ Word Ladder solver using Breadth-First Search (BFS) to find the shortest transformation path between two words, leveraging queues, hash sets, parent mapping, and path reconstruction.

This program loads a dictionary of five-letter words and validates the input data before performing the search. It determines whether two words are adjacent in the search space by checking whether they differ by one character. 

The strongest technical part is the search implementation:
- It uses a queue for BFS.
- It uses an unordered_set to avoid revisiting words.
- It uses an unordered_map to retain each discovered word's parent.

Once the destination is reached, the program follows the parent relationships backward and uses a stack to output the complete transformation path in the correct order. 
