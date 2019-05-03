#define BIORBD_API_EXPORTS
#include "../include/s2mMuscleCompound.h"

s2mMuscleCompound::s2mMuscleCompound(const s2mString &name, const s2mMusclePathChangers& wrap) :
    m_pathChanger(wrap),
    m_name(name)
{
    this->m_force.clear();
    //ctor
}

s2mMuscleCompound::s2mMuscleCompound(const s2mMuscleCompound &m)
{
    this->m_pathChanger = m.m_pathChanger;
    this->copyForce(m.m_force);
    this->m_type = m.m_type;
    this->m_name = m.m_name;
}

s2mMuscleCompound::~s2mMuscleCompound()
{
    //dtor
}

s2mMusclePathChangers &s2mMuscleCompound::pathChanger() {
    return m_pathChanger;
}

void s2mMuscleCompound::addPathObject(s2mMusclePathChanger &w)  {
    m_pathChanger.addPathChanger(w);
}

std::vector<std::shared_ptr<s2mMuscleForce> > s2mMuscleCompound::force() {
    return m_force;
}

s2mString s2mMuscleCompound::name() const {
    return m_name;
}

void s2mMuscleCompound::setName(const s2mString &name) {
    m_name = name;
}

void s2mMuscleCompound::copyForce(const std::vector<std::shared_ptr<s2mMuscleForce> > &force)
{
    m_force.clear();
    for (size_t i=0; i<force.size(); ++i)
        m_force.push_back(force[i]);
}

