#pragma once

class Egg
{
public:
    Egg();

    void setFertilized(bool fertilized);

    bool getFertilized() const;

private:
    bool isFertilized;
    
};