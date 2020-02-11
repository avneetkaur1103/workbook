// https://leetcode.com/explore/interview/card/google/67/sql-2/3044/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
    	set<string> all_emails;
  		for(string mail: emails){
  			auto pos = mail.find('@');
  			string local_name = mail.substr(0,pos);
  			string domain_name = mail.substr(pos);
  			local_name.erase(remove_if(local_name.begin(), local_name.end(), [](auto ch){ return ch == '.'}), local_name.end()); // remove .
  			if((pos = local_name.find('+')) != string::npos)
  				local_name = local_name.substr(0, pos);

  			mail = local_name + domain_name;
  			if(all_emails.find(mail) == all_emails.end())
  				all_emails.insert(mail);

  		}
  		return all_emails.size();
    }
};