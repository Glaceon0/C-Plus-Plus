int smallestValue = v.at(0);

for(i = 1; i < v.size(); ++i) {
    unsigned index = 0;
    if(v.at(i) < smallestValue) {
        smallestValue = v.at(i);
        index = i;
    }   
}