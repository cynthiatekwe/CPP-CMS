filename="main.cpp"
while read -r line
do
    # COUNTER = 5613
    name=$line
    echo "$name" >> debug.cxx
    git add .
    git commit -m "CPP-CMS DEV Added Commits"
    # $COUNTER = $COUNTER+1
    git push origin master
done < "$filename"