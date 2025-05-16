# Qt 6 C++ GUI Development - My Course Code

## About

This repository contains all the code I've written while taking the **Qt 6 C++ GUI Development for Beginners** course. The course teaches how to build cross-platform desktop GUI applications using Qt 6 and C++. As a learner, I've followed along with the lessons, coding examples, and projects to learn Qt and C++ from scratch.

The code here includes my solutions to exercises, demos, and projects from the course, like a number-guessing game, a web page downloader, and applications using Qt's widgets, dialogs, and networking features. This repo serves as my personal portfolio of progress and a reference for revisiting what I've learned.

## Repository Structure

The code is organized into folders based on the course sections. Here's the structure:

- **/cpp_basics**: My C++ refresher code, including console apps, variables, loops, functions, classes, and a number-guessing console game.
- **/qt_basics**: My first Qt GUI app and the GUI version of the number-guessing game.
- **/signals_slots**: Examples of Qt's signals and slots, including lambda functions and event handling.
- **/qt_widgets**: Code using Qt widgets like `QPushButton`, `QLineEdit`, `QLabel`, and layouts (`QHBoxLayout`, `QVBoxLayout`, etc.).
- **/dialogs**: My implementations of dialogs, including custom dialogs, `QMessageBox`, `QFontDialog`, and `QFileDialog`.
- **/resources_styling**: Code for Qt Resource System, styling with Style Sheets, and saving settings with `QSettings`.
- **/file_system**: Examples working with files and directories using `QFile` and `QDir`.
- **/networking**: Apps I built to download web pages and consume REST APIs.
- **/model_view**: My Model-View architecture examples, including `QListWidget`, `QTableWidget`, and `QStandardItemModel`.

Each folder contains:
- Source files (`.cpp`, `.h`, `.ui`).
- Qt project files (`.pro`).
- A short `NOTES.md` file with my comments on what I learned or challenges I faced.

## Prerequisites

To run the code, you need:

- **Qt 6.x**: The open-source version of Qt 6.
- **Qt Creator**: The IDE I used to write and test the code.
- **C++ Compiler**: A C++17-compatible compiler (e.g., GCC, MSVC, or Clang).
- **Operating System**: Windows, macOS, or Linux (I used [your OS, e.g., Windows/Linux/macOS]).

## Setup

1. **Install Qt 6**:
   - Download Qt 6 from [qt.io](https://www.qt.io/download).
   - Use the Qt Online Installer to install Qt Creator and Qt 6 libraries.
   - Choose a C++17-compatible compiler during setup.

2. **Clone the Repository**:
   

3. **Run the Code**:
   - Open Qt Creator.
   - Load the `.pro` file from any project folder (e.g., `qt_basics/number_guessing_gui/number_guessing_gui.pro`).
   - Select a kit (compiler and Qt version) to configure the project.
   - Build and run to see the GUI app.



## My Learning Journey

This repo tracks my progress through the course. Some challenges I faced include:
- Understanding signals and slots at first (but the demos helped!).
- Getting layouts to look right with size policies and stretches.
- Debugging networking code when APIs didn't respond as expected.



## Future Plans

I plan to:
- Add more comments to my code for clarity.
- Experiment with QML for mobile apps (after finishing this course).
- Build a personal Qt project using what I've learned.

## License

This code is for personal learning and reference. Feel free to explore it, but please respect the course's content and Qt's licensing (see [Qt Licensing](https://www.qt.io/licensing/)).

## Thanks

Big thanks to the course for teaching me Qt and C++ in a beginner-friendly way! I'm excited to keep learning and building GUI apps.