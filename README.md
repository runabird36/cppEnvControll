
# Setting Cpp development project ( custom header / source file )
---
<br>
<br>

#### Step 01. CMake : Quick start

<br>

#### 02. make project directory
```
- main.cpp
- CMakeLists.txt
----source
    - headerfile.h
    - sourcefile.cpp
    
```


<br>

#### Step 03. include_directories("${CMAKE_SOURCE_DIR}/source") 와 add_executable()에 추가하고자하는 cpp 파일 입력
```
    cmake_minimum_required(VERSION 3.0.0)
    project(cppEnv02 VERSION 0.1.0)

    include(CTest)
    enable_testing()



    include_directories("${CMAKE_SOURCE_DIR}/source")


    add_executable(cppEnv02 main.cpp source/ssong.cpp)

    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
```
<br>

#### Step 04. cmake configure and cmake build 

<br>

#### Step 05. execute 실행파일


<br>
<br>
<br>
<br>
<br>



# Setting Cpp development enviroment [Windows]
---
<br>
<br>

#### Step 1. Install prerequisites : Git , CMake , Visual Studio , vcpkg , vsCode
- [Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git)
- [CMake](https://cmake.org/install/)
- [Visual Studio](https://code.visualstudio.com/download)
- vsCode prerequisites module : C/C++, CMake, CMake Tools
    - user > settings.json
    ```
    1. ctrl + shift + p 
    2. Open user settings (JSON)
    3. add below strings
    "editor.mouseWheelZoom": true,
    "cmake.configureSettings": {
        "CMAKE_TOOLCHAIN_FILE": "{VCPKG_INSTALLED_DIR}/scripts/buildsystems/vcpkg.cmake"
    },
    ```
- [VCPKG](https://github.com/Microsoft/vcpkg#getting-started)
    ```
    cd C:\Users\phili\Documents
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
    ```
    ```
    .\vcpkg integrate install
    ```
    ```
    # search library
    .\vcpkg search sqlite

    # install library
    .\vcpkg install sqlite3:x64-windows

    # list installed library
    .\vcpkg list
    ```

<br>
<br>
<br>

#### Step 2. make main.cpp 
    ```
    # test code
    #include <sqlite3.h>
    #include <iostream>

    int main(void) {
        std::cout << sqlite3_libversion() << '\n';
        return 0;
    }
    ```

<br>
<br>
<br>

#### Step 3. make CMakeLists.txt by 'CMake: Quick Start'
- Default CMakeLists.txt contents
    ```
    cmake_minimum_required(VERSION 3.0.0)
    project(TestSQL VERSION 0.1.0)
    include(CTest)
    enable_testing()

    add_executable(TestSQL main.cpp)

    set(CPACK_PROJECT_NAME ${PROJECT_NAME})
    set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
    include(CPack)
    ``` 
<br>

- need to add **INCLUDE_DIRECTORIES** , **LINK_DIRECTORIES**
    ```
    cmake_minimum_required(VERSION 3.0.0)
    project(TestSQL VERSION 0.1.0)
    
    INCLUDE_DIRECTORIES(c:/Users/phili/Documents/vcpkg/installed/x64-windows/include/)
    
    LINK_DIRECTORIES(c:/Users/phili/Documents/vcpkg/installed/x64-windows/lib/)

    add_executable(TestSQL main.cpp)
    TARGET_LINK_LIBRARIES(TestSQL sqlite3)
    ```
- if you want to add additional libraries,
    ```
    ...
    TARGET_LINK_LIBRARIES(TestSQL sqlite3 mylib blabla_lib)
    ...
    ```


<br>
<br>
<br>

#### Step 4. Do 'CMake: Build'
- This make Debug folder and under that folder, there is projectName.exe file

<br>
<br>
<br>

#### Step 5. edit .vscode > launch.json
- ctrl + shift + P > type 'launch.json'
- add below 
    ```
    {
        // Use IntelliSense to learn about possible attributes.
        // Hover to view descriptions of existing attributes.
        // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
        "version": "0.2.0",
        "configurations": [
            {
            "name": "cl.exe - Build and debug active file",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/Debug/TestSQL.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "console": "externalTerminal",
            //"preLaunchTask": "C/C++: cl.exe build active file"
            }
        ]
    }
    ```



<br>
<br>
<br>


#### Step 6. F5 : Debugging : coding


#### Step 7. Build a Release version


---
- [How to use vcpkg with vscode and cmake ](https://www.40tude.fr/how-to-use-vcpkg-with-vscode-and-cmake/)
- [Visual Studio Code Setup](https://visitlab.pages.fi.muni.cz/tutorials/vs-code/index.html#visualstudiocodesetup/linkthevcpkgtoolchainfile)
