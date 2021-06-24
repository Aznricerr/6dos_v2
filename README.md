# 6dos_v2

This project is intented to simulate the idea of 6 degrees of seperation. The premise is on average everyone in the world is connected to eachother by 6 nodes or degrees. What I'm simulating is the scale of that idea, and that practicality of simulation. This program created adjacency list of random nodes and connections that represent the people and a set of extensive test would be put in place to determine the shortest path using dijkstra's algorithm. Edit: Recursive DFS to find distances to all connection as well as dijkstra to find shortest path.

To scale this function: N = Population, K = edges/aquaintances per node
ln(N)/ln(K) = degrees of seperation.

resources:

https://sites.psu.edu/siowfa14/2014/09/17/the-six-degrees-of-separation/#:~:text=%E2%80%9CThe%20average%20path%20length%20between,and%20K%20%3D%20acquaintances%20per%20node.&text=Yes%2C%20this%20is%20a%20formula,of%20separation%20averaging%20at%206.6.

https://en.wikipedia.org/wiki/Six_degrees_of_separation
