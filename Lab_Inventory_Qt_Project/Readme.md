# Lab Inventory Application

This is a simple Qt widget-based desktop application designed to manage and display an inventory of electronic components for an electronics lab.



##  Features

- Displays components in a table with sortable columns.
- Add, edit, search, and delete components.
- CSV import/export and auto-saving to a local inventory file.
- PDF preview of footprint selection guide.
- Reset to last saved state.
- Warning prompt on unsaved changes before closing.
- Tabbed interface for adding, searching, and editing components.
- Custom-styled table headers (green/gray).
- Automatically maximized window.
- Application icon and title for better identification.



##  Technologies

- **C++17**
- **Qt 6 (Widgets module)**
- **qmake** build system



##  How to Build (qmake)

1. **Clone the repository:**

   ```bash
   git clone https://github.com/AhmedAbo-Eita/Cpp_Programing_bootcamp.git
   cd Cpp_Programing_bootcamp/Lab_Inventory_Qt_Project/Lab_Inventory
   ```
2. Open the project in Qt Creator, and select the Lab_Inventory.pro file.
3. Choose "Release" build configuration, then click "Build".

Or from terminal (Qt command prompt):
```
qmake
mingw32-make   # or just `make` on Linux/macOS

```

## How to Run
- Run the generated Lab_Inventory.exe (found in the release/ folder).
- On first launch, the app creates a My_Inventory.csv file in the same directory.
- Use the GUI to manage your inventory of components.

## Deployment
To deploy this application on other machines:

1. Build in Release mode.
2. Use windeployqt to gather required Qt dependencies:
```
windeployqt release/Lab_Inventory.exe
```
3. Zip the contents of the release/ folder and share it.

# Usage Notes
1. Edits are only allowed from the "Edit" tab.
2. The application tracks unsaved changes and will prompt you to save before exiting.
3. All data is saved in a standard CSV format.

# Author
Created by Ahmed Aboeita
Part of a C++ Bootcamp series.
Feel free to open issues or submit pull requests!

