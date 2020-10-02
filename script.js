$(document).ready(function(){
    $(".aboutContent").hide();
    
    $(".film").mouseenter(function(){
    },
    function(){
        $(".aboutContent").fadeOut(1000);
        $(".aboutContent").fadeIn(1000);
        $(".aboutContent").slideIn(1000);
    })
    
    $(".film").mouseenter(function(){
    },
    function(){
        $(".film").animate({opacity:0.74}, 1500);
    })
    

})


