#include <iostream>

using namespace std;

void display();
void insertEnd();
void insertStart();
void insertBefore();
void insertAfter();
void deleteStart();
void deleteEnd();
void deleteAfter();
void deleteBefore();
void deleteSpecific();

int startIndex = -1, lastIndex = -1;
string record[50];

int main()
{
    int exit = 1;

    do
    {
        cout << "Enter the command number you want to execute\n";
        cout << "1. Display all records\n";
        cout << "2. Insert a record at end\n";
        cout << "3. Insert a record at start\n";
        cout << "4. Insert a record before specific value\n";
        cout << "5. Insert a record after specific value\n";
        cout << "6. Delete a record from start\n";
        cout << "7. Delete a record from end\n";
        cout << "8. Delete a record after specific value\n";
        cout << "9. Delete a record before specific value\n";
        cout << "10.Delete a specific record\n";
        cout << "0.Exit\n";
        cin >> exit;
        cout << "\n";

        switch (exit)
        {
        case 0:
            cout << "Exiting.....\n";
            break;
        case 1:
            display();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertStart();
            break;
        case 4:
            insertBefore();
            break;
        case 5:
            insertAfter();
            break;
        case 6:
            deleteStart();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            deleteAfter();
            break;
        case 9:
            deleteBefore();
            break;
        case 10:
            deleteSpecific();
            break;
        default:
            cout << "Wrong Number Entered. Please try again.....\n";
            break;
        }
    } while (exit != 0);

    return 0;
}

int search(string arr[50], string element)
{
    for (int i = startIndex; i < lastIndex; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void display()
{
    for (int i = startIndex; i < lastIndex; i++)
    {
        std::cout << record[i] << "\n";
    }
    cout << "\n";
}

void insertEnd()
{
    if (startIndex == 0 && lastIndex == 50)
    {
        std::cout << "No space\n";
    }
    else if (lastIndex == 50 && startIndex != 0)
    {
        int count = startIndex;
        while (count <= lastIndex)
        {
            record[count - 1] = record[count];
            count++;
        }
        std::cout << "Enter name at to insert: ";
        std::cin >> record[lastIndex];
        startIndex--;
    }
    else if (lastIndex == -1 && startIndex == -1)
    {
        startIndex++;
        std::cout << "Enter name at to insert: ";
        std::cin >> record[startIndex];
        lastIndex = 1;
    }
    else
    {
        std::cout << "Enter name at to insert: ";
        std::cin >> record[lastIndex];
        lastIndex++;
    }
}

void insertStart()
{
    if (startIndex == -1 && lastIndex == -1)
    {
        startIndex++;
        std::cout << "Enter name at to insert: ";
        std::cin >> record[startIndex];
        lastIndex = 1;
    }
    else if (startIndex == 0 && lastIndex == 50)
    {
        std::cout << "No space\n";
    }
    else if (startIndex > 0)
    {
        startIndex--;
        std::cout << "Enter name at to insert: ";
        std::cin >> record[startIndex];
    }
    else
    {
        int count = lastIndex;
        while (count >= startIndex)
        {
            record[count + 1] = record[count];
            count--;
        }
        std::cout << "Enter name at to insert: ";
        std::cin >> record[startIndex];
        lastIndex++;
    }
}

void insertBefore()
{
    if (startIndex == 0 && lastIndex == 50)
    {
        std::cout << "No space\n";
    }
    else if (startIndex == -1 && lastIndex == -1)
    {
        startIndex++;
        std::cout << "Enter name at to insert: ";
        std::cin >> record[startIndex];
        lastIndex = 1;
    }
    else if (lastIndex < 50)
    {
        string element;
        std::cout << "Enter element before which to be inserted: ";
        std::cin >> element;
        std::cout << "\n";
        int index = search(record, element);
        if (index == -1)
        {
            cout << "Wrong element entered\n";
            return;
        }
        int count = lastIndex;
        while (count >= index)
        {
            record[count + 1] = record[count];
            count--;
        }
        std::cout << "Enter name at to insert: ";
        std::cin >> record[index];
        lastIndex++;
    }
    else
    {
        string element;
        std::cout << "Enter element before which to be inserted: ";
        std::cin >> element;
        std::cout << "\n";
        int index = search(record, element);
        if (index == -1)
        {
            cout << "Wrong element entered\n";
            return;
        }
        int count = startIndex;
        while (count < index)
        {
            record[count - 1] = record[count];
            count++;
        }
        std::cout << "Enter name at to insert: ";
        std::cin >> record[index - 1];
        startIndex--;
    }
}

void insertAfter()
{
    if (startIndex == 0 && lastIndex == 50)
    {
        std::cout << "No space\n";
    }
    else if (startIndex == -1 && lastIndex == -1)
    {
        startIndex++;
        std::cout << "Enter  name at to insert: ";
        std::cin >> record[startIndex];
        lastIndex = 1;
    }
    else if (lastIndex < 50)
    {
        string element;
        std::cout << "Enter element after which to be inserted: ";
        std::cin >> element;
        std::cout << "\n";
        int index = search(record, element);
        if (index == -1)
        {
            cout << "Wrong element entered\n";
            return;
        }
        int count = lastIndex;
        while (count > index)
        {
            record[count + 1] = record[count];
            count--;
        }
        std::cout << "Enter name at to insert: ";
        std::cin >> record[index + 1];
        lastIndex++;
    }
    else
    {
        string element;
        std::cout << "Enter element after which to be inserted: ";
        std::cin >> element;
        std::cout << "\n";
        int index = search(record, element);
        if (index == -1)
        {
            cout << "Wrong element entered\n";
            return;
        }
        int count = startIndex;
        while (count <= index)
        {
            record[count - 1] = record[count];
            count++;
        }
        std::cout << "Enter name at to insert: ";
        std::cin >> record[index];
        startIndex--;
    }
}

void deleteStart()
{
    if (startIndex == -1)
    {
        std::cout << "Empty\n";
    }
    else if (lastIndex == 0)
    {
        std::cout << "Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }
    else
    {
        startIndex++;
    }
}

void deleteEnd()
{
    if (startIndex == -1)
    {
        std::cout << "Empty\n";
    }
    else if (lastIndex == 0)
    {
        std::cout << "Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }
    else
    {
        lastIndex--;
    }
}

void deleteAfter()
{
    if (startIndex == -1)
    {
        std::cout << "Empty\n";
    }
    else if (lastIndex == 0)
    {
        std::cout << "Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }
    else
    {
        string element;
        std::cout << "Enter element after which to be Deleted: ";
        std::cin >> element;
        std::cout << "\n";
        int index = search(record, element);
        if (index == -1)
        {
            std::cout << "Wrong element entered\n";
            std::cout << "\n";
        }
        else if (index == lastIndex - 1)
        {
            std::cout << "No element found after entered element\n";
            std::cout << "\n";
        }
        else if (index == lastIndex - 2)
        {
            lastIndex--;
        }
        else
        {
            int count = index;
            while (count < lastIndex - 2)
            {
                record[count + 1] = record[count + 2];
                count++;
            }
            lastIndex--;
        }
    }
}

void deleteBefore()
{
    if (startIndex == -1)
    {
        std::cout << "Empty\n";
    }
    else if (lastIndex == 0)
    {
        std::cout << "Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }
    else
    {
        string element;
        std::cout << "Enter element before which to be Deleted: ";
        std::cin >> element;
        std::cout << "\n";
        int index = search(record, element);
        if (index == -1)
        {
            std::cout << "Wrong element entered\n";
            std::cout << "\n";
        }
        else if (index == startIndex)
        {
            std::cout << "No element found before entered element\n";
            std::cout << "\n";
        }
        else if (index == startIndex + 1)
        {
            startIndex++;
        }
        else
        {
            int count = index;
            while (count >= startIndex + 2)
            {
                record[count - 1] = record[count - 2];
                count--;
            }
            startIndex++;
        }
    }
}

void deleteSpecific()
{
    if (startIndex == -1)
    {
        std::cout << "Empty\n";
    }
    else if (lastIndex == 0)
    {
        std::cout << "Only 1 element found and deleted\n";
        startIndex = lastIndex = -1;
    }
    else
    {
        string element;
        std::cout << "Enter element after which to be Deleted: ";
        std::cin >> element;
        std::cout << "\n";
        int index = search(record, element);
        if (index == -1)
        {
            std::cout << "Wrong element entered\n";
        }
        else
        {
            int count = index;
            while (count < lastIndex - 1)
            {
                record[count] = record[count + 1];
                count++;
            }
            lastIndex--;
        }
    }
}