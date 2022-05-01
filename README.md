# Account Generator
An example application and showcase of Micro ToolKit.
This Account Generator acts as a command line application for managing accounts and storing account data on a file.
This project example was created for the purpose of generating a specified amount of random accounts or create accounts tailored to my needs in an easy and quick way.

## Program Startup
![Program Startup](https://github.com/Zoobop/AccountGenerator/blob/master/gitImages/accountGen_i1.png "Program Startup")

When the program starts, the application interface appears and is used similarly to a typical command line. The short list of comaands are displayed below.

## Database Commands
![Database Commands](https://github.com/Zoobop/AccountGenerator/blob/master/gitImages/accountGen_i2.png "Database Commands")

By inputing the 'help' command, as described at the top of the screen, it displays the list of commands used to interact with the local database.

Codewise, the data structures used to store information such as the 'commands' and the 'database registry' were ```mtk::Map<TKey, TVal>``` and ```mtk::List<T>``` respectively. There were also a few utility methods used from the ```mtk::StringUtils``` class to help with parsing user input.

## Adding New User (Manual)
![Adding New User](https://github.com/Zoobop/AccountGenerator/blob/master/gitImages/accountGen_i3.png "Adding New User")

The user input requirements for adding a new user are not too strict, as this application's purpose was mainly to demonstrate a small, simple project using the MicroToolKit.

To save new user to the database, you must also **COMMIT** to see a persistent change.

## Adding New User (Automatic)
