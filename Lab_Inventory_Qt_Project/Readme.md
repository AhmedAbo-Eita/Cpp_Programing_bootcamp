# Lab Inventory Application

This is a simple Qt widget-based desktop application designed to manage and display an inventory of electronic components for an electronics lab.

---

## Features

- Displays components in a table with sortable columns.
- Shows detailed information including manufacturer part number, quantity, component type, footprint, and storage location.
- Custom styled table headers with mint green color and gray row headers.
- Maximized window by default for easy visibility.
- Icon and window title set for better identification.

---

## Technologies

- C++17
- Qt 6 (Widgets module)
- CMake build system

---

## How to Build

1. Clone the repository:

   ```bash
   git clone https://github.com/AhmedAbo-Eita/Cpp_Programing_bootcamp.git
   cd Cpp_Programing_bootcamp\Lab_Inventory_Qt_Project\Lab_Inventory
   ```

2. Create a build directory and navigate into it:
    ```bash
    mkdir build && cd build 
    ```

3. Run CMake to configure the project:
    ```bash
    cmake ..
    ```
4. Build the project
    ```bash
    cmake --build .
    ```

## Usage
- Launch the application to view the inventory table.
- The table supports sorting by clicking on the headers.
- The UI is non-editable to prevent accidental modifications.
- To extend functionality, you can add component data via code or connect to a database.

## Contact
Created by Ahmed Aboeita as part of C++ Bootcamp projects.
Feel free to open issues or submit pull requests!

