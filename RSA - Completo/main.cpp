#include <iostream>
#include "Rsa.h"
using namespace std;

int main(){
    string mensaje;
    mensaje = "14528965768692212464514517406723554203544686364758305235266123509647840842543632870195843224307110712887566167217735721293764990249356182694595208800957367290357809942796861500213075730121477225636405496834034844096297127429341217264121741213069265698663062528372832216383117837739178979208004980415119077390942830357740105224496789111067270228068183275437127651859857477456526942913633235451610133075394762729005214778401980648948372935980358009508177308322145144377253811064743693768403900646310489233327482032627117244044696108851761899037904102345056775527199114845929834668146519946525313270214149446442540412317070936624171655011189394879403523801231218223482587101513466694032406303309607939251127752204920675347006194355594793863605724942364286640623232828467827410537809061241482237998774841431529145970189680189473889571120823800679986148646093329150063181778878488063627311577633389392067753819721963425197819048636777462664911585620127339826480806974098373486345975644987012890938170892028621662971532215556110089884809242997973522060182461835801476690690776205566892949454835626317337827042470031359711810548965527760906223729577277851901891899335446228945825702559268603011916532852881980118508386978792211368895550830301415013048282277214083861868597846168970616524405052866863014453991171315690635556556626359015023571493843296941242013400367191897465108152768351284466670337170993552517823508346433695898361795525053377704370790322234676954409134331407804602042331745549605046573810787575525689976464602006719095078426404336617368570344751037579459563613848628096266151091211248480040664818497148638566766366131403640213605122326451485392978146863925918756694434332287719579105277989308973544562664043781121192974300237236792568764062766743185077192163953636417241763212506659322914920160079064283956395954369332586368670962659979780308356177531673687861781069817326960944703671738182828851338252219311323341691874871012995721762431709910231618740198975013839342181384136487198127134996217108227338815187072215235544223749671290709626227854137469545717899049350140902534570970328494740943287595764407091150672154925154520175075674913490473627571528274085211873816361642069378423482165785436416997050082893468520512894822773391064002107734219840055640279188400490595600226620959954231343740696568138083419419887530536406824042986487241014966823346542521081900052542933481859814080263822122324959646709446747836713762595672920480541625480764041548685979";
    Rsa receptor(1024);//genera claves y recibe mensaje
/*
    ZZ n= conv<ZZ>("22754358257010251103027726460447348487493241772988412056064432519172344070319092643744803446961232989369817826309495699602201409938956686841283892906863415716762901548314131711605757628786629392049806304791354648337053548876220002682878107305935977917179078548493419628157866171853318197851024466793622390862071967154221971713728855021834895182398603773779309874127486916594873674030512110879137424859605474895741510008921442191102771814765126120259977067343655582537671016756983805456589847879709032861970159165289348630375743756353074231111112584284004195837489645912013724030407875881056175423908089832031026565997");
    ZZ e= conv<ZZ>("160881796038177215848663852830936019953296496293559472377087350881890686986363708560349040149326004342754536988240498601570426998737558255612616504124781737697837074277022430858940485426498155443552229624898389396697140734511255782247921754292228734293251798285061257033914651651108655614304119591080746195717");//*/
    /*
    ZZ n,e;
    cin>>n>>e;//*/
/*
    Rsa emisor(n,e);//recibe claves <n,e> y encripta mensaje
    cout<<"mensaje cifrado: "<<endl<<emisor.cifrado(mensaje)<<endl;//*/

    //cin>>mensaje;
    cout<<receptor.descifrado(mensaje);//*/
    return 0;
}

///Revisar todo para ntl!!!