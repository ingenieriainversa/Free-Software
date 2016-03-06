/*
 * Integrated Library Management System v0.01
 * Item.java
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

public class Item
{
    private int id;
    private String title;
    private boolean available;
    private boolean returned;
    private String timestamp;
    private int pages;
    private User userToLoan;
    private int loanDays;
    
    public Item(int id, String title)
    {
        this.id = id;
        this.title = title;
        available = true;
        returned = true;
        timestamp = timestamp();
        userToLoan = null;
        loanDays = 0;
    }
    
    private String timestamp(){
        Date currentDate=new Date(); 
        SimpleDateFormat spanishFormat = new SimpleDateFormat("yyyy/MM/dd H:mm:ss");
        String timestamp = spanishFormat.format(currentDate);
        return timestamp;
    }
    
    public int getItemId(){return id;}
    public String getItemTitle(){return title;}
    public boolean getItemAvailable(){return available;}
    public boolean getItemReturned(){return returned;}
    public String getItemTimestamp(){return timestamp;};
    public User getUserToLoan(){return userToLoan;};
    public int loanDays(){return loanDays;};
    
    public String getDetails(){
        if(returned) {
            available = true;
        } else {
            available = false;
        }
        return id+"|"+title+"|"+available+"|"+timestamp;
    }
    
    public void loan(User user, int days){
        userToLoan = user;
        loanDays = days;
    }
}
