# employee-record-system
The Employee Record System (ERS) is a C++ program that manages and integrates employee profiles with their corresponding address information. Key features include:

Data Integration:
- Combines employee records (ID, name, department) with address data (street, city, state, zip)
- Uses a unique employee ID (aID) to link records

File Processing:
- Reads employee data from one file and address data from another
- Supports custom file paths provided by the user

Menu-Driven Interface:
- Interactive console menu with options to:
    - Load employee/address data files
    - Display all records
    - Search by employee ID or ZIP code
    - Sort records by ID or ZIP code
    - Print individual records by index

Data Representation:
- Uses object-oriented design with employee, address, and combined record classes
- Formats street addresses with zero-padded numbers (e.g., 042 Main St)
- Maps department enums to human-readable names (e.g., RESEARCH_AND_DEVELOPMENT)

Core Operations:
- Automatic matching of employees to addresses via ID
- Insertion sort for record ordering
- Memory management with proper constructors/destructors
- Error handling for file access and invalid inputs

Key Classes:
- employee: Stores personnel data (ID, name, department)
- address: Manages physical address components
- record: Inherits from both employee and address to create unified records

The system provides a command-line interface for businesses to manage and query employee location data alongside departmental information.
