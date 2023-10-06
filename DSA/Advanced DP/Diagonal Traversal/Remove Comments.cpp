        vector<string> code;
        string str;
        bool isInsideBlockComment = false;
        for(string &line : source)
        {
			// If we are not inside any block comment, then reset str
            if(!isInsideBlockComment)
                str = "";
            for(int i = 0; i < line.length(); i++)
            {
	
                if((line[i] == '/' || line[i] == '*') && i+1 < line.length())
                {
					// If next two characters are /*, and we are not inside any comment block, then this marks the start of a comment block
                    if(line.substr(i,2) == "/*" && !isInsideBlockComment)
                    {
                        isInsideBlockComment = true;
                        i++;
                    }
					// If next two characters are */, and we are inside any comment block, then this marks the end of a comment block
                    else if(line.substr(i,2) == "*/" && isInsideBlockComment)
                    {
                        isInsideBlockComment = false;
                        i++;
                    }
					// If next two characters are //, and we are not inside any comment block, then we reject the rest of the line
                    else if(line.substr(i,2) == "//" && !isInsideBlockComment)
                    {
                        break;
                    }
                    else if(!isInsideBlockComment)
                        str.push_back(line[i]);
                }
                else if(isInsideBlockComment)
                    continue;
				// If we are not within any comment block, then we add the characters to str
                else
                    str.push_back(line[i]);
            }
			// If we are not within any comment block, and str is not empty, then this line is eligible to be shown in output
            if(str != "" && !isInsideBlockComment)
                code.push_back(str);
        }
        return code;
