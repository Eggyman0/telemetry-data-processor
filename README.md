# telemetry-data-processor
This script is used to read, process, package, and output the information from a dataset containing information from iot telemetry sensors. This dataset is obtained from [kaggle.com](https://www.kaggle.com/datasets/garystafford/environmental-sensor-data-132k).

## UML Diagrams
<details>
  <summary>Draft UML Diagram</summary>
  <img width="986" height="824" alt="2310_GroupProject_UML" src="https://github.com/user-attachments/assets/bb22925a-3210-4754-a6dd-5dcf123bedfa" />
</details>

<details>
  <summary>Final UML Diagram</summary>
  <img width="1563" height="1272" alt="2310_Final_UML" src="https://github.com/user-attachments/assets/f5716f1c-5a3b-449d-ba52-4ac8e9275ebe" />
</details>

## What have we done?
### Modifications Made Since the Initial UML Diagram / Class Discussion
* vectors store strings instead of other data types like double or bool
  - Makes it easier to export data to another csv file.
* Fully fleshed implementations of more classes
  - Conversion Class
  - Addition of enumeration header to help keep track of sensor metrics
* Relationships rearragned
  - Due to how the project ended up being programmed, the association connections from the initial UML diagram changed to composition/aggregation relationships. For example, multiple classes contain a pointer to the vectors located in SensorData but none of those classes specifically own SensorData objects.
 
Notable Assumptions Made:
  - Format of data after conversion
     - Timestamps being converted into a readable format
     - For each file, having one column for timestamp and one extra column for each unique sensor ID
---
### ChatGPT Usage
Common questions asked to ChatGPT were often related to debugging code and error messages
  - Example:
    ChatGPT was asked, "What is this error?", with our code provided for reference
```
C:/msys64/ucrt64/include/c++/15.1.0/bits/stl_vector.h:1263: std::vector<_Tp, _Alloc>::reference std::vector<_Tp, _Alloc>::operator[](size_type) [with _Tp = SensorData*; _Alloc = std::allocator<SensorData*>; reference = SensorData*&; size_type = long long unsigned int]: Assertion '__n < this->size()' failed.
```
It showed that the function used to check if a sensor ID was unique had backwards logic. The use of ChatGPT saved valuable time in the debugging process.

An additional problem it helped us solve was the long runtime required to write the new csv files. This was solved by having the accessor methods from the SensorData class return a reference to its vectors instead of a copy. It dramatically lowered the amount of time of writing the files from hours to seconds (not exaggerating here). We suspect it was due to memory issues due to copying vectors multiple times when sharing pointers to those vectors bewteen multiple classes.

Besides debugging, ChatGPT partially generated the logic of the time conversion from epoch to UTC standard time in Y/M/D/H/M/S format with the use of the ctime library.

---
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
---
### Implementation
 Deliverables:
  - UML Diagram for all classes(Hub, DataImporter, DataExporter, SensorData, DataConversion)
  - Code Files for program(.h and .cpp files for all classes & main)
  - Explanation:
    - **Hub**: Acts as an interface for the user to utilize the implemented functions through the various classes
    - **DataImporter**: 'Reader' of sorts, which reads the given data file(iot_telementry_data.csv), sorts it, and stores it into a usable format(vectors) based on each sensor
    - **DataExporter**: 'Writer' of sorts, which writes by gathering all processed data and composing it
    - **SensorData**: Acts as a container object for each individual sensor
    - **DataConversion**: Convert strings to double, double to string, Ferinheit to Celcius, and epoch time to Y/M/D/H/M/S

Methods of testing included extra functions (not present in UML diagram) made specifically for testing
  - Test functions would output specific lines of code based on the what was tested
  - Expected lines printing would mean expected functionality 

