OlympicSportTracker
===================

Web crawler designed to analyze the popularity of various Winter Olympic Sports

Developed a web crawler using the C++ programming language. 
It had to crawl web pages and retrieve the necessary information regarding Winter Olympics Sports.

Program Structure:
The program has 6 classes: 
• Data_slot and Data : they contain functions to update and access their 
attributes. 
• A template class Element represents a node in a list. It include data from Data class 
as well as pointers used to access the previous or the next nodes. 
• A template class represent objects in the main list: the class is instantiated with 
Data_slot and Data. It has as attribute a pointer head, which points to the associated sublist. 
• A HashMap class. This class is a template as well. In the program, it will be instantiated using 
Data_slot and Data. It has as attribute a pointer first, which points to the main list. 
• A BuildHashMap class. This class takes the Url (seed) as input and fetches the data necessary to build the Hashmap.

Furthermore the following functions have been written to update the Hash Map.
• void processInput(string  seed)(class  BuildHashMap): this function takes the url as argument. It then uses curl command to retrieve the necessary information from the web .
• string CopyFiletoString()(class  BuildHashMap):: This function stores the file into a buffer.
• HashMap* BuildHashMapObject(string SportsArray[11],string SportValueArr[11],int length) (class  BuildHashMap): this functions stores the values of sports and its respected values to the hashmap object. 	 
