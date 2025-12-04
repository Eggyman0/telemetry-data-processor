# telemetry-data-processor
This script is used to read, process, package, and output the information from a dataset containing information from iot telemetry sensors. This dataset is obtained from [kaggle.com](https://www.kaggle.com/datasets/garystafford/environmental-sensor-data-132k).

## UML Diagram First Draft (subject to many changes)
<img width="986" height="824" alt="2310_GroupProject_UML" src="https://github.com/user-attachments/assets/bb22925a-3210-4754-a6dd-5dcf123bedfa" />

## What have we done?
### Modifications Made Since the Initial UML Diagram / Class Discussion
* vectors store strings instead of other data types like double or bool
  - Needed in order to export data into another csv file
* Full implementations of more classes
  - Example: Conversion Class
 
* Many assumptions were made along the design process of the project
  - Format of data after conversion
     - Ex: Time being converted into a readable format 

### ChatGPT Usage
* Common questions asked to ChatGPT were often related to debugging code and error messages
  - Example:
* ChatGPT was asked, "What is this error?", with our code provided for reference
```
C:/msys64/ucrt64/include/c++/15.1.0/bits/stl_vector.h:1263: std::vector<_Tp, _Alloc>::reference std::vector<_Tp, _Alloc>::operator[](size_type) [with _Tp = SensorData*; _Alloc = std::allocator<SensorData*>; reference = SensorData*&; size_type = long long unsigned int]: Assertion '__n < this->size()' failed.
```
* It showed that the function used to check if a sensor ID was unique had backwards logic
  - Fixing the code was the challenging part, but the use of ChatGPT saved valuable time in the debugging process
* ChatGPT partially generated the logic of the time conversion from epoch to UTC standard time in Y/M/D/H/M/S format
  
* Verification process involved testing sections of the code in the console
  -Example:
    - Once the changes suggested by ChatGPT were made in the example error message above, the code began working as intended 

### Collaboration
* Lot of individual answers were created during the design phase of the project, specifically in the UML diagram
  - Different thought processes of each individual led to unique approaches to the design of the UML diagram design
  
* After considering all given options, the best option was determined through reasoning
  
* The project had many sections that could be worked towards
  - Examples being different classes, sections in UML diagram, and other minor tasks
* Tasks were split based on many factors, like preferences, expertise, etc.

* Specific examples of work distribution:
  - Edmund: Specific sections of the UML Diagram, implementing classes like DataImporter, SensorData, etc.
  - Nakul: Specific sections of UML Diagram, implementing DataConversion class, Readme, etc.

### Implementation
* Deliverables:
  - UML Diagram for all classes(Hub, DataImporter, DataExporter, SensorData, DataConversion)
  - Code Files for program(.h and .cpp files for all classes & main)
  - Explanation:
    - Hub: Acts as an interface for the user to utilize the implemented functions through the various classes
    - DataImporter: 'Reader' of sorts, which reads the given data file(iot_telementry_data.csv), sorts it, and stores it into a usable format(vectors) based on each sensor
    - DataExporter: 'Writer' of sorts, which writes by gathering all processed data and composing it
    - SensorData: Acts as a container object for each individual sensor
    - DataConversion: Convert strings to double, double to string, Ferinheit to Celcius, and epoch time to Y/M/D/H/M/S

* Methods of testing included extra functions (not present in UML diagram) made specifically for testing
  - Test functions would output specific lines of code based on the what was tested
  - Expected lines printing would mean expected functionality 

