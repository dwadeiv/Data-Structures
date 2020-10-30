/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
/* finished. do not touch. */
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName) {
    
    // if we are passed an empty list, just create a new head node, and return
    if (head == NULL)
    {
        cout << "adding: " << countryName << " (HEAD)" << endl;
        head = new Country;
        head->name = countryName;
        head->numberMessages = 0;
        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        //case where it's a new head Country
        cout << "adding: " << countryName << " (HEAD)" << endl;
        Country *c = new Country;
        c->name = countryName;
        c->numberMessages = 0;
        c->next = head;
        head = c;
    }else{
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
        Country *newCountry = new Country;
        newCountry->name = countryName;
        newCountry->numberMessages = 0;
        newCountry->next = previous->next;
        previous->next = newCountry;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) {
    //TODO: Complete this function
    if(head == NULL){
        return;
    }
    Country* temp_1 = head;
    Country* temp_2 = head->next;
    if(head->name == countryName){
        head = head->next;
        delete temp_1;
        return;
    }
    while(temp_2->next != NULL && temp_2->name != countryName){
        temp_2 = temp_2->next;
        temp_1 = temp_1->next;
    }
    if(temp_2->name != countryName){
        cout << "Country does not exist." << endl;
        return;
    }
    temp_1->next = temp_2->next;
    delete temp_2;
    return;
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    int num_countries = 6;
    string countries[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
    // deleteEntireNetwork();
    Country* prev = NULL;
    for(int i = 0; i < num_countries; i++)
    {
        insertCountry(prev, countries[i]);
        prev = searchNetwork(countries[i]);
    }
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
// Search until the head is NULL, or we find the country
    Country* ptr = head;
    while (ptr != NULL && ptr->name != countryName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
* Purpose: Creates a loop from last node to the country specified.
* @param countryName name of the country to loop back
* returns pointer to last node before loop creation (to break the loop)
*/
Country* CountryNetwork::createLoop(string countryName)
{
    //TODO: Complete this function
    if(head == NULL){
        return head;
    }
    Country* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Country* loop_back = searchNetwork(countryName);
    if(loop_back == NULL){
        return temp;
    }
    temp->next = loop_back;
    return temp;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    //TODO: Complete this function
    if(head == NULL){
        return;
    }
    Country* temp = head;
    string delete_name;
    while(temp != NULL){
        cout << "deleting: " << temp->name << endl;
        delete_name = temp->name;
        temp = temp->next;
        deleteCountry(delete_name);
    }
    head = NULL;
    cout << "Deleted network" << endl;
    return;
}

/*
*Purpose: to detect loop in the linkedlist
* @param
* returns true if loop is detected. Otherwise return false.
*/
bool CountryNetwork::detectLoop() {
    //TODO: Complete this function
    bool loop = false;
    if(head == NULL){
        return loop;
    }
    Country* slow = head;
    Country* fast = head->next;
    while(slow != NULL && fast != NULL && fast->next != NULL){
        if(slow->name == fast->name){
            loop = true;
            return loop;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return loop;
}

/*
* Purpose: Take the chunk of nodes from start index to end index
*          Move that chunk at the end of the List
*@param: start index
*@param: end index
* return none
*/
void CountryNetwork:: readjustNetwork(int start_index, int end_index)
{
    //TODO: Complete this function
    if(head == NULL){
        cout << "Linked List is Empty" << endl;
        return;
    }
    if(start_index > end_index){
        cout << "Invalid indices" << endl;
        return;
    }
    if(start_index < 0){
        cout << "Invalid start index" << endl;
        return;
    }
    if(end_index < 0){
        cout << "Invalid end index" << endl;
        return;
    }
    int start_count = 0;
    int end_count = 0;
    Country* start = head;
    Country* second_to_start = head;
    Country* end = head;
    Country* temp = head;
    while(start_count != start_index){
        if(start == NULL){
            cout << "Invalid start index" << endl;
            return;
        }
        second_to_start = start;
        start = start->next;
        start_count ++;
    }
    while(end_count != end_index){
        if(end == NULL || end->next == NULL){
            cout << "Invalid end index" << endl;
            return;
        }
        end = end->next;
        end_count ++;
    }
    while(temp-> next != NULL){
        temp = temp->next;
    }
    if(start_count == 0){
        head = end->next;
        temp->next = start;
        end->next = NULL;
        return;
    }
    second_to_start->next = end->next;
    temp->next = start;
    end->next = NULL;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    Country* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr->next != NULL)
        {
            cout << ptr->name << " -> ";
            ptr = ptr->next;
        }
        cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
