// first view at variant && visit
//
struct Fluid
{
};
struct LightItem
{
};
struct HeavyItem
{
};
struct FragileItem
{
};

struct VisitPackage
{
   void operator()(Fluid &) { cout << "Fluid" << endl; }
   void operator()(LightItem &) { cout << "LightItem" << endl; }
   void operator()(HeavyItem &) { cout << "HeavyItem" << endl; }
   void operator()(FragileItem &) { cout << "FragileItem" << endl; }
};

void variant_visit_01()
{

   variant<Fluid, LightItem, HeavyItem, FragileItem> package;

   package = FragileItem();
   visit(VisitPackage(), package);

   package = LightItem();
   visit(VisitPackage(), package);

   package = HeavyItem();
   visit(VisitPackage(), package);

   package = Fluid();
   visit(VisitPackage(), package);

   return;
}
