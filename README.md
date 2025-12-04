# telemetry-data-processor
This script is used to read, process, package, and output the information from a dataset containing information from iot telemetry sensors. This dataset is obtained from [kaggle.com](https://www.kaggle.com/datasets/garystafford/environmental-sensor-data-132k).

## UML Diagram First Draft (subject to many changes)
<img width="986" height="824" alt="2310_GroupProject_UML" src="https://github.com/user-attachments/assets/bb22925a-3210-4754-a6dd-5dcf123bedfa" />

## What have we done?
### Modifications Made Since the Initial UML Diagram / Class Discussion
* vectors store strings instead of other data types like double or bool.
  - Needed in order to export data into another csv file
* Full implementations of more classes
  - Example: Conversion Class
* Many assumptions were made along the design process of the project
  - Format of data after conversion
     - Ex: Time being converted into a readable format 

### ChatGPT Usage
AI was used for debugging errors that we had. So far, none of the code has been generated.
One of the first hurdles was this error message:
```
C:/msys64/ucrt64/include/c++/15.1.0/bits/stl_vector.h:1263: std::vector<_Tp, _Alloc>::reference std::vector<_Tp, _Alloc>::operator[](size_type) [with _Tp = SensorData*; _Alloc = std::allocator<SensorData*>; reference = SensorData*&; size_type = long long unsigned int]: Assertion '__n < this->size()' failed.
```
For the prompt, we simply asked "what is this error?" and provided our code for reference. After that, it showed us that the function used to check if a sensor ID was unique had backwards logic. Fixing the code was the easy part, but having ChatGPT as a second helping hand shaved off most of our debugging time.

### Collaboration
Work was mostly split up among the different classes.

### Implementation
For testing, we had an extra function (not in the UML diagram) in the DataImporter class to output specific lines that were read from the csv file. This ensured that we were reading the file correctly before implementing the file writing class. Additionally, when debugging, extra lines were used to print out things in the terminial to ensure that certain processes were operating accordingly.
