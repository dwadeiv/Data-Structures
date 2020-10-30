/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
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
    // TODO
    // Country* head = new Country;
    head = NULL;

}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    // TODO
    if(previous == NULL){
        Country* new_country = new Country;
        new_country->name = countryName;
        new_country->next = head;
        head = new_country;
        cout << "adding: " << countryName << " (HEAD)" << endl;
    }
    else{
        Country* new_country = new Country;
        new_country->name = countryName;
        new_country->next = previous->next;
        previous->next = new_country;
        cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    }

}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    // TODO
    CountryNetwork::insertCountry(NULL, "United States");
    CountryNetwork::insertCountry(head, "Canada");
    CountryNetwork::insertCountry(head->next, "Brazil");
    CountryNetwork::insertCountry(head->next->next, "India");
    CountryNetwork::insertCountry(head->next->next->next, "China");
    CountryNetwork::insertCountry(head->next->next->next->next, "Australia");

}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    // TODO
    if(head == NULL){
        return NULL;
    }
    Country* search = head;
    while(search->next != NULL && search->name != countryName){
        search = search->next;
    }
    if(search->name == countryName){
        return search;
    }
    else {
        return NULL;
    }
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    // TODO
    Country* check = searchNetwork(receiver);
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    else if(check == NULL){
        cout << "Country not found" << endl;
        return;
    }
    Country* temp = head;
    while(temp != NULL){
        temp->message = message;
        temp->numberMessages++;
        cout << temp->name << " [# messages received: " << temp->numberMessages << "] received: " << temp->message << endl;
        if(temp->name == receiver){
            break;
        }
        temp = temp->next;
    }
    return;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    // TODO
    cout << "== CURRENT PATH ==" << endl;
    if(head == NULL){
        cout << "nothing in path" << endl;
        cout << "===" << endl;
        return;
    }
    Country* temp = head;
    while(temp != NULL){
        cout << temp->name << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "===" << endl;
}
