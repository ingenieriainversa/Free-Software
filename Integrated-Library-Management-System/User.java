/*
 * Integrated Library Management System v0.01
 * Users.java
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

public class User
{
    private String name;
    private String surname;
    private int age;
    private boolean active;

    public User(String name, String surname, int age)
    {
        this.name = name;
        this.surname = surname;
        this.age = age;
        active = true;
    }
    
    public String getUserName(){return name;}
    public String getUserSurname(){return surname;}
    public int getUserAge(){return age;}
    public boolean getUserActive(){return active;}
    public String getDetails(){return name + " " + surname + ", " + age + " - " + "Active: " + active;}
}
