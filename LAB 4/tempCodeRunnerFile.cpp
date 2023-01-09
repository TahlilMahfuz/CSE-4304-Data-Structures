for(int i=0;i<student.size();i++)
    {
        if(student.front()==sandwitch.front())
        {
            student.pop();
            sandwitch.pop();
            return;
        }
    }