# A very basic example of Conway's Game of Life
This project is an incredibly simple version of Conway's Game of Life that I made in C++ using the SFML library for graphics. 

This implmentation is really nothing special. There is absolutely no interaction from the user, no way to change the size or number of cells, the cells' starting state are psuedo-random.

The second version of this project can run as small as a 1x1 cell width, but it's pretty slow. Personally I like the 3x3 cells the best. Anything bigger than 5x5 is somewhat dissapointing. Version 1 will crash if you attempt to run 1x1 cells. For version 1 5x5 and smaller will result in sub 10 fps. I didn't measure the fps of the second version, but it doesn't seem to tank much until it's ran with cells smaller than a 3x3.

# 1x1 (Compression hurts this. It looks cooler when actually running)
[1x1 Cells](gifs/1x1.gif)

# 3x3 (My personal favorite. There is still a lot of compression visible)
[3x3 Cells](gifs/3x3.gif)

# The two versions
There are two versions of this project. The first one was my first attempt and there are some silly things in it, but I could've went back and refactored it. The reason I didn't was because the first version uses a draw call for each cell (which is incredibly slow), and I wanted to give vertex arrays a try. I made a version two because I thought it would be easier than going back and trying to work a vertex array into the mess that is version 1. In hindsight, I was probabaly right, though it could've been done in version 1.

# Any tips?
As you may have noticed, I am not very good at writing C++ code. I'm still fairly new to it, so if I did anything that would be considered "poor practice" or if there is a bug or whatever, please tell me. I haven't used github for too long, but I assume the "Issues" tab would be a good place for stuff like that.

# Thanks!
Thank you for checking out my project!
