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
import java.util.Date;
import java.text.SimpleDateFormat;

public class User
{
    private int id;
    private String name;
    private String surname;
    private int age;
    private boolean employee;
    private boolean active;
    private String timestamp;
    private Roles rol;
    
    public User(int id, String name, String surname, int age, boolean employee)
    {
        this.id = id;
        this.name = name;
        this.surname = surname;
        this.age = age;
        this.employee = employee;
        active = true;
        timestamp = timestamp();
    }
    
    private String timestamp(){
        Date currentDate=new Date(); 
        SimpleDateFormat spanishFormat = new SimpleDateFormat("yyyy/MM/dd H:mm:ss");
        String timestamp = spanishFormat.format(currentDate);
        return timestamp;
    }
    
    public int getUserId(){return id;}
    public String getUserName(){return name;}
    public String getUserSurname(){return surname;}
    public int getUserAge(){return age;}
    public boolean getUserEmployee(){return employee;}
    public boolean getUserActive(){return active;}
    public String getTimestamp(){return timestamp;};
    public String getDetails(){return id+"|"+name+"|"+surname+"|"+age+"|"+employee+"|"+active+"|"+timestamp;}
}
