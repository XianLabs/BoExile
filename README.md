# BoExile
AI bot and network manipulator for PoE
Currently outdated!


**** This project has become outdated to the point of even if you update offsets, it wont work. Some core changes were done with entities which will break all projects before 3.16. Please see my new PoE software project, which is up-to-date and working well - OK POE. ****

Every object is an entity. Every entity contains a list of Components. A component is a data structure containing relevant info (file name of entity, 
string representing which component it is, a hash key, and any relevant data to that component based on its' string name.

Example:

Entity* e = new Entity();

ComponentList* CL = e->GetComponentList();
e->SetComponentValue(CL->GetComponent("Positioned"), 0x40, 100); //Sets the X axis to 100: 0x40 is the offset in memory from the component base of "Positioned" for a character's X axis


