let loc_now  = "Iwade";
let loc_dest = "Miyamae";

function changeLocation(){
  [loc_now, loc_dest] = [loc_dest, loc_now];
  document.getElementById("locations").textContent = loc_now + " to " + loc_dest;

  // if(loc_now === "Iwade"){
  //   document.getElementById("locations").textContent = "Miyamae to Iwade";
  // }else{
  //   document.getElementById("locations").textContent = "Iwade to Miyamae";
  // }
  
  // console.log("changeLocation()");
}