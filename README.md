# Solar System Physics Simulation
![](https://github.com/AustinDevoreUWF/Physics_Sim/blob/main/SolarSystemGIF.gif)

Language: C++

Graphics/APIs: OpenGL, SFML
## 🌀 Project OverviewA high-performance
2D/3D orbital mechanics simulation built from the ground up using C++ and OpenGL. Unlike typical simulations that use pre-built game engines, this project features a custom physics engine and a manual rendering pipeline.
## 🚀 Key Technical Features
Custom N-Body Physics Engine: Implemented Newtonian Mechanics using Euler Integration to calculate gravitational forces ($F = G \frac{m_1 m_2}{r^2}$) between celestial bodies.Low-Level Rendering: Leveraged OpenGL for hardware-accelerated graphics, managing vertex buffers and coordinate transformations manually.Mathematical Modeling: Built a custom math utility library for Vector2D/3D operations, handling distance calculations and velocity vectors without external physics libraries.Real-time Interaction: Integrated SFML for window management and event handling, with OpenGL used for the user to "fly" around the space to change views and grasp scale.
## 🛠️ Challenges Overcome
Floating Point Precision: Optimized calculations to prevent "orbital drift" during long-duration simulations.Performance: Managed the rendering loop to maintain a stable 60 FPS even with multiple concurrent gravitational actors.

**From Theory to Implementation:** Translated theoretical physics notes and Newtonian equations directly into C++ logic. By deriving the mechanics manually rather than using pre-existing libraries or generative tools, I ensured 100% architectural transparency and a deep understanding of the simulation's mathematical foundation
