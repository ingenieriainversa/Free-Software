/*
 * Integrated Library Management System v0.01
 * Ilms.java
 * Copyleft - 2014  Javier Dominguez Gomez
 * Written by Javier Dominguez Gomez <jdg@member.fsf.org>
 * GnuPG Key: 6ECD1616
 * Madrid, Spain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

import java.util.ArrayList;

public class Library
{
    private String name;
    private String address;
    private boolean open;
    private int numEmployees;
    private ArrayList<User> users;
    private ArrayList<Item> items;
    private int nextUserId;
    private int nextItemId;

    public Library(String name, String address)
    {
        this.name = name;
        this.address = address;
        this.open = true;
        users = new ArrayList<User>();
        items = new ArrayList<Item>();
        nextUserId = 1;
        nextItemId = 1;
    }
    
    /* Selectors methods */
    public String getName(){return name;}
    public String getAddress(){return address;}
    public int getNumUsers(){return users.size();}
    public boolean getOpen(){return open;}
    public int getNumEmployees()
    {
        numEmployees = 0;
        for(User user : users) {
            if(user.getUserEmployee() == true) {
                numEmployees++;
            }
        }
        return numEmployees;
    }
    
    public User getUser(int userId)
    {
        if((userId >= 1) && (userId < nextUserId)) {
            User selectedUser = users.get(userId - 1);
            if(selectedUser.getUserId() != userId) {
                System.out.println("Internal error: User id " +
                                   selectedUser.getUserId() +
                                   " was returned instead of " +
                                   userId);
                selectedUser = null;
            }
            return selectedUser;
        }
        else {
            System.out.println("User id: " + userId +
                               " does not exist.");
            return null;
        }
    }
    
    /* Users methods */
    public void createUser(String name, String surname, int age, boolean employee)
    {
        users.add(new User(nextUserId, name, surname, age, employee));
        nextUserId++;
    }
    
    public void addUser(User user)
    {
        users.add(user);
    }

    public void listAllUsers()
    {
        for(User user : users) {
            System.out.println(user.getDetails());
        }
    }

    public void listBySurname(String surname)
    {
        for(User user : users) {
            if(user.getUserSurname().contains(surname)) {
                System.out.println(user.getDetails());
            }
        }
    }

    public void removeUser(int index)
    {
        if(indexUsersValid(index)) {
            users.remove(index);
        }
    }

    private boolean indexUsersValid(int index)
    {
        boolean valid;

        if(index < 0) {
            System.out.println("Index cannot be negative: " + index);
            valid = false;
        } else if(index >= users.size()) {
            System.out.println("Index is too large: " + index);
            valid = false;
        } else {
            valid = true;
        }
        return valid;
    }
    
    /* Items methods */
    public void createItem(String title)
    {
        items.add(new Item(nextItemId, title));
        nextItemId++;
    }
    
    public void addItem(Item item)
    {
        items.add(item);
    }

    public void listAllItems()
    {
        for(Item item : items) {
            System.out.println(item.getDetails());
        }
    }

    public void listByTitle(String title)
    {
        for(Item item : items) {
            if(item.getItemTitle().contains(title)) {
                System.out.println(item.getDetails());
            }
        }
    }

    public void removeItem(int index)
    {
        if(indexItemsValid(index)) {
            items.remove(index);
        }
    }

    private boolean indexItemsValid(int index)
    {
        boolean valid;

        if(index < 0) {
            System.out.println("Index cannot be negative: " + index);
            valid = false;
        } else if(index >= items.size()) {
            System.out.println("Index is too large: " + index);
            valid = false;
        } else {
            valid = true;
        }
        return valid;
    }
}
