## Goal
We are starting this project as a way to eventually build a Game Engine with Physics Simulation capabilties. 
### Roadmap 
- First phase of this project would be to implement generic graphics applications like Event Loop, Basic Rendering, Camera, Lighting etc.
- After that we can move on to actual Gaming based functionlities like Scenes, Environment, Basic player system, Input/Output
- After this Ambitious goal is achieved we can dive into adding real Physics to our engine. We can add Animations, Audio management etc.
- After this we will still have so much to conquer but we can think about that later

### Repo
I have created the repo on GitHub to maintain this project and have this repo structure for beginning:
```
Repo
├── Assets/ -> for textures, images, etc
├── CMake/ -> for handling cmake related things
├── Engine/ -> the main engine (src)
│   ├── Core/ -> for handling eventloop and general
│   │   │      purpose things. This runs the whole engine.
│   │   ├── Application/ -> to handle event loop and managing data structs
│   │   └── Events/ -> events in the loop
│   ├── Renderer/ -> renders the image
│   │   └── OpenGL/ -> API wrappers
│   └── Scene/-> for objects and what to render
├── Sandbox -> This will contain the main function and this will 
│                instantiate the Engine. For testing and other things.
├── CMakeLists.txt
└── README.md
All the current files in the directory is temporary for git to commit directory structure
```
There is a issue board i have setup for the project.
Go to Repo -> Projects -> Gaming Engine Development. 
You will see a board with multiple state of issues there. Look into it. For now I am closing issue#1