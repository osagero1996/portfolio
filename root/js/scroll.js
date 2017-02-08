// for the about section
        $(document).ready(function (){
            $("#click").click(function (){
                $('html, body').animate({
                    scrollTop: $("#about").offset().top
                }, 2000);
            });
        });


        $(document).ready(function (){
            $("#aboutNav").click(function (){
                $('html, body').animate({
                    scrollTop: $("#about").offset().top
                }, 1500);
            });
        });

//for the resume section
        $(document).ready(function (){
            $("#resumeNav").click(function (){
                $('html, body').animate({
                    scrollTop: $("#resume").offset().top
                }, 1500);
            });
        });

//for the projects section
$(document).ready(function (){
            $("#projectNav").click(function (){
                $('html, body').animate({
                    scrollTop: $("#project").offset().top
                }, 1500);
            });
        });

//for the contacts section
$(document).ready(function (){
            $("#contactNavs").click(function (){
                $('html, body').animate({
                    scrollTop: $("#contact").offset().top
                }, 1500);
            });
});




$(document).ready(function (){
            $("#name").click(function (){
                $('html, body').animate({
                    scrollTop: $("#top").offset().top
                }, 1500);
            });
});

$(document).ready(function (){
            $("#downButton").click(function (){
                $('html, body').animate({
                    scrollTop: $("#about").offset().top
                }, 1500);
            });
});
