# RestaurantWaitingListSystem
Implemented a customer waiting list that can be used by a restaurant. The program uses linked list to implement the queue-like data structure. <br />
<h3> <b>How the system works? </b> </h3>
<ul><li>Groups are added to the wait list when they call-ahead or when they arrive at the restaurant. Groups are always added to the end of the wait list. <br/>
  <b>Note:</b> these call-ahead groups will still need to check in when they arrive so the host/hostess knows they are waiting in the restaurant. </li>
<li>The system will require that each name used be unique. So when a group is added to the wait list, the system must make sure that no other group is already using that name. </li>
<li>When a table with N seats becomes available in the restaurant, the system returns the name of the first group that is in the restaurant and can sit at a table with N seats (i.e. the number of seats at the table is greater than or equal to the number of people in that group). Note that the group selected may not be the first (or even the second or third) group on the wait list. </li> </ul>
<h3><b> Commands: </b></h3>
The commands used by this system are listed below and are to come from standard input.
<ul> <li><b>q</b> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Quit the program. </li>
  <li> <b>?</b> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp  List the commands used by this program and a brief description of how to use each one.</li>
  <li> <b> a &ltsize&gt &ltname&gt </b>&nbsp Add the group to the wait list using the given group size and name specifying the group is waiting in the restaurant. The group’s information is added to the end of the list. If the name already exists in the wait list, give an error message and do not add the information. </li>
  <li> <b>c &ltsize&gt &ltname&gt </b> &nbsp Add the group to the wait list using the given group size and name specifying the group as a call ahead group. The group’s information is added to the end of the list. If the name already exists in the wait list, give an error message and do not add the information. </li>
  <li> <b> w &ltname&gt </b> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Mark the call ahead group using the given name as waiting in the restaurant. If the name does not exist is the wait list or is not a call ahead group, give an error message. </li>
  <li> <b> r &lttable-size&gt </b> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Retrieve and remove the first group on the wait list that is waiting in the restaurant and is less than or equal to the table size. Note that “first” is the group that has been in the wait list the longest. </li>
  <li> <b> l &ltname&gt </b> &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp List total number of groups that are in the wait list in front of the group specified by the given name. Also list the size of each group that are in the wait list ahead of the group specified by the given name. If the name does not exist, give an error message. </li>
  <li> <b> d </b> 
&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Display the total number of groups in the wait list. Also display the names, group size and in-restaurant status of all groups in the wait list in order from first to last. </li></ul><br />
 
