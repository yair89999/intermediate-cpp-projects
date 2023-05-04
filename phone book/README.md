<h1>This is the phone book</h1>

<ul>
  <h4>Options in the phone book:</h4>
  <il></li>
  <il>1. Print the whole book</li>
  <il>2. Add a name+phone number</li>
  <il>3. Get a phone number by name</li>
  <il>4. Get a name by a full/part of a phone number</li>
</ul>

<h4>Example for the outputs:</h4>
<pre>
Phone book Actions:
1. Print the book
2. Add a name and a phone number
3. Get a phone number by name
4. Get a name by full a phone number or a part of it
Chosen action:
1
Phone book:
Name     |  Phone Number
Yair        054-789-1234
Yona        043-876-1234
Ido         050-876-1234
joni        046-123-8765

Chosen action:
2
Enter the name: Yair
Enter the number(format=000-000-0000): 052-123-1234
The name and number you wanted to add, added to the book

Chosen action:
3
Enter the name/name part you want to search by: Y
Name      | number
Yair        054-789-1234
Yair        052-123-1234
Yona        043-876-1234

Chosen action:
4
Enter the number/number part you want to search by: 05
Name      | number
Yair        054-789-1234
Yair        052-123-1234
Ido         050-876-1234
</pre>
