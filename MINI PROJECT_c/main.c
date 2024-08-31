#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CONTACTS 10

// Structure to represent a contact
typedef struct {
    char name[50];
    int age;
    int phone_number;
    int date_of_birth;
    char address[50];
} Contact;

// Function to add a contact
void add_contact(Contact *contact) {
    printf("Name: ");
    scanf(" %[^\n]s", contact->name); // Allow spaces in the name
    printf("Age: ");
    scanf("%d", &contact->age);
    printf("Phone Number: ");
    scanf("%d", &contact->phone_number);
    printf("Date of Birth (YYYYMMDD): ");
    scanf("%d", &contact->date_of_birth);
    printf("Address: ");
    scanf(" %[^\n]s", contact->address); // Allow spaces in the address
}

// Function to display a contact
void display_contact(Contact contact) {
    printf("\nName: %s\n", contact.name);
    printf("Age: %d\n", contact.age);
    printf("Phone Number: %d\n", contact.phone_number);
    printf("Date of Birth: %d\n", contact.date_of_birth);
    printf("Address: %s\n", contact.address);
    printf("-------------------------\n");
}

// Function to search for a contact by name
void search_contact(Contact contacts[], int num_contacts) {
    char name[50];
    printf("Enter the name to search: ");
    scanf(" %[^\n]s", name);
    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            display_contact(contacts[i]);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    }
}

// Function to delete a contact by name
void delete_contact(Contact contacts[], int *num_contacts) {
    char name[50];
    printf("Enter the name to delete: ");
    scanf(" %[^\n]s", name);
    int found = 0;
    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (int j = i; j < *num_contacts - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*num_contacts)--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found!\n");
    } else {
        printf("Contact deleted successfully!\n");
    }
}

// Function to update a contact's details
void update_contact(Contact contacts[], int num_contacts) {
    char name[50];
    printf("Enter the name of the contact to update: ");
    scanf(" %[^\n]s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Updating contact %s\n", name);
            add_contact(&contacts[i]);
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

// Function to sort contacts by name
void sort_contacts_by_name(Contact contacts[], int num_contacts) {
    for (int i = 0; i < num_contacts - 1; i++) {
        for (int j = i + 1; j < num_contacts; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

// Function to sort contacts by phone number
void sort_contacts_by_phone(Contact contacts[], int num_contacts) {
    for (int i = 0; i < num_contacts - 1; i++) {
        for (int j = i + 1; j < num_contacts; j++) {
            if (contacts[i].phone_number > contacts[j].phone_number) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

// Function to display all contacts
void display_all_contacts(Contact contacts[], int num_contacts) {
    if (num_contacts == 0) {
        printf("No contacts to display!\n");
    } else {
        for (int i = 0; i < num_contacts; i++) {
            display_contact(contacts[i]);
        }
    }
}

// Function to save contacts to a file
void save_contacts(Contact contacts[], int num_contacts) {
    FILE *file = fopen("contacts.dat", "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    fwrite(&num_contacts, sizeof(int), 1, file);
    fwrite(contacts, sizeof(Contact), num_contacts, file);
    fclose(file);
    printf("Contacts saved successfully!\n");
}

// Function to load contacts from a file
void load_contacts(Contact contacts[], int *num_contacts) {
    FILE *file = fopen("contacts.dat", "rb");
    if (file == NULL) {
        printf("No saved contacts found.\n");
        return;
    }
    fread(num_contacts, sizeof(int), 1, file);
    fread(contacts, sizeof(Contact), *num_contacts, file);
    fclose(file);
    printf("Contacts loaded successfully!\n");
}

int main() {
    int choice;
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;

    load_contacts(contacts, &num_contacts);

    printf("WELCOME TO PHONE BOOK\n");

    while (1) {
        printf("\nMENU\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Update Contact\n");
        printf("6. Sort Contacts by Name\n");
        printf("7. Sort Contacts by Phone Number\n");
        printf("8. Save Contacts\n");
        printf("9. Load Contacts\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_contacts < MAX_CONTACTS) {
                    add_contact(&contacts[num_contacts]);
                    num_contacts++;
                } else {
                    printf("Phone book is full!\n");
                }
                break;
            case 2:
                display_all_contacts(contacts, num_contacts);
                break;
            case 3:
                search_contact(contacts, num_contacts);
                break;
            case 4:
                delete_contact(contacts, &num_contacts);
                break;
            case 5:
                update_contact(contacts, num_contacts);
                break;
            case 6:
                sort_contacts_by_name(contacts, num_contacts);
                printf("Contacts sorted by name.\n");
                break;
            case 7:
                sort_contacts_by_phone(contacts, num_contacts);
                printf("Contacts sorted by phone number.\n");
                break;
            case 8:
                save_contacts(contacts, num_contacts);
                break;
            case 9:
                load_contacts(contacts, &num_contacts);
                break;
            case 10:
                printf("Are you sure you want to close the phone book? (1 for yes, 2 for no): ");
                int ans;
                scanf("%d", &ans);
                if (ans == 1) {
                    save_contacts(contacts, num_contacts);
                    printf("The phone book is closed. Have a good day!\n");
                    return 0;
                } else {
                    printf("The phone book is not closed. You can continue.\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
