# Maze_C++
## By Florian FloRide Reimat
# About 
An Maze Generator + Solver written in C++

## Examples:
```
┌───────────────┬───────────────────────┬───────────┬───────────┬───┬───────────┐
│               │                       │           │           │   │           │
│   ┌───┐   ╷   └───┬───╴   ╷   ╶───────┴───────┐   ╵   ╷   ┌───┘   └───╴   ╷   │
│   │   │   │       │       │                   │       │   │               │   │
│   │   │   ├───┬───┼───┐   └───┬───╴   ╶───────┘   ╷   │   └───╴   ╶───────┴───┤
│   │   │   │   │   │   │       │                   │   │                       │
│   ╵   └───┘   ╵   │   │   ╶───┼───┬───╴   ╶───┐   └───┤   ╷   ╶───┬───────┐   │
│                   │   │       │   │           │       │   │       │       │   │
│   ╷   ╶───┬───╴   ╵   └───╴   ╵   ├───────┬───┼───┐   └───┼───────┤   ╷   ╵   │
│   │       │                       │       │   │   │       │       │   │       │
├───┴───┐   ├───╴   ╷   ╷   ╷   ╶───┘   ╶───┘   │   ├───────┘   ╶───┼───┘   ╶───┤
│       │   │       │   │   │                   │   │               │           │
│   ╷   ╵   ├───────┼───┴───┘   ╶───┐   ╷   ╷   ╵   │   ┌───┬───┐   ├───┐   ┌───┤
│   │       │       │               │   │   │       │   │   │   │   │   │   │   │
├───┴───────┼───┐   ├───╴   ╶───┐   └───┼───┴───┐   │   ╵   ╵   └───┘   ├───┤   │
│           │   │   │           │       │       │   │                   │   │   │
│   ╶───┬───┘   ╵   └───╴   ╶───┼───────┤   ┌───┘   │   ╷   ╷   ╶───────┤   │   │
│       │                       │       │   │       │   │   │           │   │   │
│   ┌───┴───────────────╴   ╶───┘   ┌───┘   ├───────┼───┴───┘   ╶───────┘   ╵   │
│   │                               │       │       │                           │
│   └───┐   ╶───┬───╴   ┌───╴   ╶───┴───╴   ╵   ┌───┴───┐   ╷   ╷   ╷   ╷   ┌───┤
│       │       │       │                       │       │   │   │   │   │   │   │
├───┐   ╵   ┌───┼───╴   │   ╷   ┌───┐   ┌───╴   ├───┐   │   └───┴───┤   │   │   │
│   │       │   │       │   │   │   │   │       │   │   │           │   │   │   │
│   │   ╷   ╵   ├───┐   └───┼───┘   ├───┼───╴   ╵   ╵   ╵   ╷   ╷   ├───┼───┤   │
│   │   │       │   │       │       │   │                   │   │   │   │   │   │
│   ╵   ├───┬───┘   │   ╷   │   ╷   │   └───────╴   ╶───┬───┘   └───┤   ╵   ╵   │
│       │   │       │   │   │   │   │                   │           │           │
│   ┌───┤   ╵   ╶───┤   ├───┤   │   └───────╴   ╷   ┌───┼───╴   ╷   ╵   ╷   ╶───┤
│   │   │           │   │   │   │               │   │   │       │       │       │
│   │   ╵   ╶───┬───┘   ╵   ├───┤   ┌───╴   ╷   ├───┤   ╵   ╷   ├───┬───┤   ╷   │
│   │           │           │   │   │       │   │   │       │   │   │   │   │   │
│   ╵   ╷   ┌───┤   ╷   ╷   ╵   │   │   ┌───┘   ╵   │   ╷   ├───┤   │   ╵   └───┤
│       │   │   │   │   │       │   │   │           │   │   │   │   │           │
│   ╶───┴───┤   │   └───┼───╴   └───┤   ├───┐   ╶───┼───┘   ╵   ╵   ├───┐   ╶───┤
│           │   │       │           │   │   │       │               │   │       │
├───╴   ╶───┤   └───╴   ├───╴   ╶───┼───┤   ├───────┘   ┌───────┐   ╵   ├───╴   │
│           │           │           │   │   │           │       │       │       │
│   ┌───╴   ├───────╴   └───────┐   ╵   ╵   │   ┌───╴   ╵   ╶───┴───────┼───╴   │
│   │       │                   │           │   │                       │       │
└───┴───────┴───────────────────┴───────────┴───┴───────────────────────┴───────┘
```
20 x 20 Maze

TODO:
- [ ] UI:
	- [ ] CLI 
	- [ ] Console
	- [ ] Qt (or else)
- [ ] Generator:
	- [x] Fusion
	- [ ] Backtrack
- [ ] Solver:
	- [ ] Left / Right Hand
	- [ ] Pledge
	- [ ] Djikstra
	- [ ] A*
